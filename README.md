# 🚀 Blockchain Transaction Simulator using Arduino Uno

## 📌 About the Project
This project is a **miniature blockchain simulator built with an Arduino Uno** that mimics how transactions are added, mined into blocks, and stored in a ledger — all via the **Serial Monitor**. It’s designed as an **educational tool** for beginners to visualize blockchain mechanics without using a traditional network.

## 🎯 Key Features
- ✅ Add custom transactions via Serial input  
- ⛏ Mine blocks using a simplified Proof-of-Work (PoW) algorithm  
- 📜 Display a full ledger with hash representation  
- 🧠 Understand blockchain fundamentals (hashing, nonce, transaction pooling)

## 🔧 Hardware Used
- **Arduino Uno**
- **USB Cable** (for programming and serial communication)
- 💻 PC with Arduino IDE installed

## 🧑‍💻 How It Works
1. Open the **Serial Monitor** (baud rate: 9600)
2. Use commands:
   - `add sender receiver amount id` → Adds a transaction  
   - `mine` → Mines current transactions into a block  
   - `display` → Shows the blockchain ledger

3. Example:
   ```
   add Alice Bob 10 tx001
   mine
   display
   ```

## 💡 Sample Output
```
✅ Transaction added.
⛏ Block Mined! ✅
Block Hash: 5a2
Nonce: 3
===== 📜 Blockchain Ledger =====
Tx ID: tx001 | From: Alice → To: Bob | Amount: 10 ETH | Hash: 53b
================================
```

## 📂 Project Files
- `blockchain_simulator.ino` – Main Arduino code  
- `README.md` – Project documentation

## 📷 Snapshots
You can include images like:
- 📸 Serial Monitor output
- 🧩 Code snippets (screenshots)
- 🛠 Arduino Uno setup on your desk
- 🎓 Faculty demo pictures

## 👩‍💻 Developed By
**Sandhiya Sri**  
Aspiring Data Scientist & Full Stack Developer  
VIT Vellore | Intern @ Jol Energy  
📧 srirev8523@gmail.com
