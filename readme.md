# TicTacToe

## Descrierea Proiectului

TicTacToe este un joc clasic de tipul "X și O" în care doi jucători își alternează mișcările pe o tablă de 3x3. Fiecare jucător încearcă să-și așeze simbolul (X sau O) pe tablă astfel încât să formeze o linie de trei simboluri identice, fie pe orizontală, verticală sau diagonală.

## Regulile Jocului TicTacToe

1. **Tabla de Joc**: Tabla este o grilă 3x3, formată din 9 celule.
2. **Mișcările**: Fiecare jucător își alege un simbol (X sau O) și își plasează simbolul într-o celulă goală.
3. **Obiectivul**: Primul jucător care reușește să plaseze trei simboluri identice într-o linie (orizontală, verticală sau diagonală) câștigă jocul.
4. **Jocul Se Încheie**: Jocul se încheie când un jucător câștigă sau când tabla este completă fără a exista un câștigător (remiză).

## Tipuri de Date Noi Declarate

1. **`CellState`** (Enum):
   - **Tip de date**: Enumerație.
   - **Descriere**: Reprezintă starea fiecărei celule de pe tablă.
   - **Valori**: `Empty` (celula este goală), `X` (celula conține simbolul X), `O` (celula conține simbolul O).

2. **`Cell`** (Structură):
   - **Tip de date**: Structură.
   - **Descriere**: Reprezintă o celulă de pe tablă, incluzând coordonatele și starea sa.
   - **Membru**:
     - `int row` (rândul celulei pe tablă).
     - `int col` (coloana celulei pe tablă).
     - `CellState state` (starea celulei).

3. **`Board`** (Clasă):
   - **Tip de date**: Clasă.
   - **Descriere**: Reprezintă tabla de joc TicTacToe, gestionând starea fiecărei celule și oferind funcții pentru manipularea tablării.
   - **Membru**:
     - `Cell _cells[3][3]` (matricea de celule pe tablă).
   - **Metode**:
     - `void SetCell(int row, int col, CellState state)` (setează starea unei celule).
     - `CellState GetCell(int row, int col) const` (obține starea unei celule).
     - `bool IsFull() const` (verifică dacă tabla este completă).
     - `bool CheckWin(CellState state) const` (verifică dacă un jucător a câștigat).

4. **`Player`** (Clasă):
   - **Tip de date**: Clasă.
   - **Descriere**: Reprezintă un jucător, inclusiv simbolul său și capacitatea de a face mișcări pe tablă.
   - **Membru**:
     - `CellState _symbol` (simbolul jucătorului).
   - **Metode**:
     - `Player(CellState symbol)` (constructor pentru a seta simbolul jucătorului).
     - `CellState GetSymbol() const` (obține simbolul jucătorului).
     - `void MakeMove(Board &board, int row, int col)` (efectuează o mișcare pe tablă).

5. **`GameEngine`** (Clasă):
   - **Tip de date**: Clasă.
   - **Descriere**: Reprezintă motorul jocului care controlează logica principală, inclusiv schimbarea jucătorilor și verificarea stării de terminare a jocului.
   - **Membru**:
     - `Board _board` (tabla de joc).
     - `Player _player1` (primul jucător).
     - `Player _player2` (al doilea jucător).
     - `Player* _currentPlayer` (jucătorul curent).
   - **Metode**:
     - `GameEngine(Player player1, Player player2)` (constructor pentru a inițializa jucătorii).
     - `void Init()` (inițializează jocul).
     - `void Run()` (rulează jocul).
     - `void SwitchPlayer()` (schimbă jucătorul curent).
     - `bool CheckGameOver() const` (verifică dacă jocul s-a terminat).



