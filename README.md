# TicTacToe

## Descrierea Proiectului

TicTacToe este un joc clasic de tipul "X și O" în care doi jucători își alternează mișcările pe o tablă de 3x3. Fiecare jucător își plasează simbolul (X sau O) pe tablă cu scopul de a forma o linie de trei simboluri identice.

## Structura Fișierelor

### 1. `main.cpp`
- **Descriere:** Fișierul principal al aplicației care inițializează jocul.
- **Funcționalitate:** 
  - Creează instanțe pentru jucători (X și O).
  - Inițializează motorul jocului (`GameEngine`).
  - Pornește execuția jocului apelând metoda `Run()` a motorului de joc.

### 2. `board.hpp` și `board.cpp`
- **Descriere:** Definirea și implementarea clasei `Board`, care gestionează starea tabloului de joc.
- **Funcționalitate:**
  - **Membre:**
    - `_cells[3][3]`: matrice care reprezintă celulele tabloului.
  - **Metode:**
    - `void SetCell(int row, int col, CellState state)`: setează starea unei celule specificate.
    - `CellState GetCell(int row, int col) const`: returnează starea unei celule.
    - `bool IsFull() const`: verifică dacă tabla este completă.
    - `bool CheckWin(CellState state) const`: verifică dacă un jucător a câștigat.

### 3. `player.hpp` și `player.cpp`
- **Descriere:** Definirea și implementarea clasei `Player`, care reprezintă un jucător din joc.
- **Funcționalitate:**
  - **Membre:**
    - `_symbol`: simbolul jucătorului (X sau O).
  - **Metode:**
    - `Player(CellState symbol)`: constructor care inițializează simbolul jucătorului.
    - `CellState GetSymbol() const`: returnează simbolul jucătorului.
    - `void MakeMove(Board &board, int row, int col)`: permite jucătorului să efectueze o mișcare pe tablă.

### 4. `game_engine.hpp` și `game_engine.cpp`
- **Descriere:** Definirea și implementarea clasei `GameEngine`, care controlează logica jocului.
- **Funcționalitate:**
  - **Membre:**
    - `_board`: instanța tabloului de joc.
    - `_player1` și `_player2`: instanțele jucătorilor.
    - `_currentPlayer`: pointer către jucătorul curent.
  - **Metode:**
    - `GameEngine(Player player1, Player player2)`: constructor care inițializează jucătorii.
    - `void Init()`: inițializează starea jocului.
    - `void Run()`: rulează bucla principală a jocului.
    - `void SwitchPlayer()`: schimbă jucătorul curent.
    - `bool CheckGameOver() const`: verifică dacă jocul s-a terminat.

### 5. `painter.hpp` și `painter.cpp`
- **Descriere:** Definirea și implementarea clasei `Painter`, care este responsabilă pentru afișarea tabloului de joc.
- **Funcționalitate:**
  - **Metode:**
    - `void DrawBoard(const Board& board)`: afișează tabla de joc în consolă, utilizând simboluri pentru fiecare celulă (X, O sau un punct pentru celulele goale).

### 6. `Makefile`
- **Descriere:** Fișierul de configurare pentru compilare.
- **Funcționalitate:**
  - Definește variabile pentru compilator și opțiunile de compilare.
  - Specifică regulile pentru compilarea fișierelor sursă în fișiere obiect și pentru crearea executabilului.
  - Include o regulă `clean` pentru ștergerea fișierelor obiect și a executabilului.

