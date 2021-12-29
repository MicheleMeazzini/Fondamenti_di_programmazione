class PuzzleBobble{

    char schema[12][8];

public:

    PuzzleBobble();
    void print();
    PuzzleBobble& fire(const int, const char);
    int height();
    PuzzleBobble& scroll();
    void compact();
};