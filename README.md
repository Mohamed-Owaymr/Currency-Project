# 🧮 Currency‑Project

> A simple and efficient C++ program for converting between different currencies, built to strengthen problem‑solving and programming skills.

---

## 🎯 Situation  
I developed this project to improve my C++ skills and to create a utility that converts values between different currencies. While working through backend/console‑based programming I needed a real‑world context to apply learning about data files, file handling, modularity, and user interaction.

---

## 🧰 Task  
My goal was to build a clean, modular, and well‑documented program in C++ that could:  
- Read currency conversion data from an external file.  
- Accept user input in one currency and convert it into another.  
- Handle multiple currency types (e.g., USD, EUR, GBP, …) and perhaps support adding/removing currencies in the future.  
- Be structured in a maintainable way (using separate header files, libraries, clear separation of logic and data).  
- Include a simple user‑friendly interface (console) and good error‑handling.

---

## 🚀 Action  
To achieve this, I did the following:  
1. **Design & Structure**  
   - Created folders: `DataFiles/`, `HeaderFiles/`, `Librarys/`, `Screens/` to organise code and data.  
   - Defined clear headers (`.h`) and implementation files (`.cpp`) for separation of concerns (e.g., currency conversion logic vs UI).  
   - Used consistent naming and clean code practices (comments, meaningful variable names).

2. **Data Handling**  
   - Stored conversion rates in an external file (inside `DataFiles/`) so that the application can update rates without recompiling.  
   - Implemented file reading function(s) to load currency names and rates at program startup.

3. **User Interface & Logic**  
   - Provided menu options to the user: select source currency, select target currency, enter amount, get converted amount.  
   - Performed validation on user input (e.g., invalid currency code, non‑numeric amount).  
   - Encapsulated conversion logic so it can be reused and extended.

4. **Testing & Documentation**  
   - Tested with multiple scenarios: small amounts, large amounts, same currency conversion, invalid inputs.  
   - Added comments in code and created this README to document purpose, usage, and structure.  
   - Prepared the project for publication on GitHub with clear folder structure and descriptive commit messages.

---

## ✅ Result  
- Delivered a working console application in C++ that successfully converts between currencies using external data files.  
- Created a clean and maintainable code‑base that can be extended (e.g., new currencies, GUI front‑end in future).  
- Enhanced my skills in file I/O, modular programming, data structures, and problem‑solving mindset.  
- Published the code on GitHub so others (including me in the future) can review, reuse, and improve it.

---

## 📂 Project Structure  
```
Currency‑Project/
│
├── DataFiles/            ← external currency data files (rates, codes)  
├── HeaderFiles/          ← .h files (interfaces, declarations)  
├── Librarys/             ← implementation files (.cpp) or reusable modules  
├── Screens/              ← console UI screens or mock‑ups  
├── CurrencySystemRunner.h
└── README.md             ← this file  
```

---

## 🛠 How to Build & Run  
1. Clone the repository  
   ```bash
   git clone https://github.com/Mohamed‑Owaymr/Currency‑Project.git
   ```  
2. Navigate to the project directory  
   ```bash
   cd Currency‑Project
   ```  
3. Compile the program  
   ```bash
   g++ ‑std=c++17 ‑o currency_converter Librarys/*.cpp Screens/*.cpp DataFiles/*.cpp ‑I HeaderFiles  
   ```  
4. Run the executable  
   ```bash
   ./currency_converter
   ```  
5. Follow the prompts: select source currency → select target currency → enter amount → view result.  
6. To update rates: edit the file inside `DataFiles/` and restart the program.

---



## 🎉 Why This Project Matters  
- **For me**: Solidifies foundational C++ skills: modular code, file handling, user interaction, error checking.  
- **For others**: Serve as a starter utility or reference for how to build a simple real‑world console application in C++.  
- **For employers / portfolio**: Demonstrates ability to think through project lifecycle: from requirement → design → implementation → documentation.

---

## 🧭 Future Enhancements  
- Add support for live exchange rates (via an API).  
- Expand UI with a graphical interface (Qt or SDL).  
- Add more currencies, including less common ones.  
- Provide reverse conversion or multi‑conversion mode.  
- Include unit tests (Google Test).  
- Add logging & error reporting for invalid/missing rate files.

---

## 📦 License  
This project is open source and available under the [MIT License](LICENSE).  

---

## 🙏 Acknowledgements  
Thank you for reviewing this project!  
If you found it useful or have suggestions, please open an issue or submit a pull request.

---

## 📧 Contact  
GitHub: [Mohamed‑Owaymr](https://github.com/Mohamed-Owaymr)  
Happy coding! 👍
