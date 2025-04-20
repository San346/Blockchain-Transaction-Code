#define MAX_TRANSACTIONS 5
#define MAX_LEDGER 10  // Max number of transactions in the ledger

struct Transaction {
  String sender;
  String receiver;
  int amount;
  String transactionID;
};

Transaction transactionPool[MAX_TRANSACTIONS];
int transactionCount = 0;

Transaction ledger[MAX_LEDGER];
int ledgerCount = 0;

// Simulated hash function (not secure)
String simpleHash(String input, int nonce) {
  int hash = 0;
  for (int i = 0; i < input.length(); i++) {
    hash += input.charAt(i);
  }
  hash += nonce;
  return String(hash, DEC); // Decimal format to match screenshot
}

void addTransaction(String sender, String receiver, int amount, String transactionID) {
  if (transactionCount < MAX_TRANSACTIONS) {
    transactionPool[transactionCount++] = {sender, receiver, amount, transactionID};
    Serial.println("✅ Transaction added.");
  } else {
    Serial.println("⚠️ Transaction pool full. Please mine the block!");
  }
}

void mineBlock() {
  if (transactionCount == 0) {
    Serial.println("⚠️ No transactions to mine.");
    return;
  }

  String blockData = "";
  for (int i = 0; i < transactionCount; i++) {
    blockData += transactionPool[i].sender + transactionPool[i].receiver + String(transactionPool[i].amount) + transactionPool[i].transactionID;
  }

  int nonce = 0;
  String blockHash;
  do {
    blockHash = simpleHash(blockData, nonce);
    nonce++;
  } while (!blockHash.startsWith("0"));

  Serial.println("⛏ Block Mined! ✅");
  Serial.print("Block Hash: ");
  Serial.println(blockHash);
  Serial.print("Nonce: ");
  Serial.println(nonce);

  for (int i = 0; i < transactionCount && ledgerCount < MAX_LEDGER; i++) {
    ledger[ledgerCount++] = transactionPool[i];
  }

  transactionCount = 0;
}

void displayBlockchain() {
  if (ledgerCount == 0) {
    Serial.println("ℹ️ No transactions in ledger.");
    return;
  }

  Serial.println("===== 📜 Blockchain Ledger =====");
  for (int i = 0; i < ledgerCount; i++) {
    String data = ledger[i].sender + ledger[i].receiver + String(ledger[i].amount) + ledger[i].transactionID;
    String hash = simpleHash(data, 0);  // Basic hash without PoW
    Serial.print("Tx ID: ");
    Serial.print(ledger[i].transactionID);
    Serial.print(" | From: ");
    Serial.print(ledger[i].sender);
    Serial.print(" → To: ");
    Serial.print(ledger[i].receiver);
    Serial.print(" | Amount: ");
    Serial.print(ledger[i].amount);
    Serial.print(" ETH | Hash: ");
    Serial.println(hash);
  }
  Serial.println("================================");
}

void setup() {
  Serial.begin(9600);
  Serial.println("🚀 Blockchain Transaction Simulator Initialized!");
  Serial.println("Commands: 'add sender receiver amount id' | 'mine' | 'display'");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input.startsWith("add ")) {
      input = input.substring(4);
      int firstSpace = input.indexOf(" ");
      int secondSpace = input.indexOf(" ", firstSpace + 1);
      int thirdSpace = input.indexOf(" ", secondSpace + 1);

      if (firstSpace == -1 || secondSpace == -1 || thirdSpace == -1) {
        Serial.println("⚠️ Invalid format. Use: add sender receiver amount id");
        return;
      }

      String sender = input.substring(0, firstSpace);
      String receiver = input.substring(firstSpace + 1, secondSpace);
      int amount = input.substring(secondSpace + 1, thirdSpace).toInt();
      String id = input.substring(thirdSpace + 1);

      addTransaction(sender, receiver, amount, id);
    } 
    else if (input == "mine") {
      mineBlock();
    } 
    else if (input == "display") {
      displayBlockchain();
    } 
    else {
      Serial.println("⚠️ Invalid command. Use: 'add sender receiver amount id' | 'mine' | 'display'");
    }
  }
}
