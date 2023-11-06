# Stack---Parsing-ASM-File-C-
Parses an ASM File contents, using vectors.

NOTE: this was one of the projects I made back in 2022 Winter Quarter in my CSS 342 Class.

 /* Loads a program stored in the filename location.
    Ensures that the stack is EMPTY and any previous program is REMOVED. */
    void LoadProgram(string filename);

    /* RUNS the entire program and RETURNS the final value (the only one left
     in the stack). If there is more than one value in the stack after the program
     has completed, THROW AN ERROR */
    int Run();

    /* RUNS the NEXT LINE of the program and RETURNS 0.
     * If there are no more lines it returns -1 */
    int Next();

    /* prints the current stack. */
    friend ostream& operator << (ostream& COUT, CPU& a);

    /* Your CPU must support the following language. All values are only integers.
     * If an operation takes two inputs from the stack and there aren't two inputs, then throw an error. */

    /* PSH val -- pushes val onto the stack. */
    int PSH();

    /* ADD -- Pops the top two values from the stack and pushes the sum of them onto the stack */
    int ADD();

    /* SUB -- Pops the top two values from the stack and pushes the difference of the second value
     * minus the first onto the stack */
    int SUB();

    /* MULT -- Pops the top two values from the stack and pushes the product of them onto the stack */
    int MULT();

    /* DIV -- Pops the top two values from the stack and pushes the second value divided by the first
     * onto the stack (note: only the integer portion).  Div by 0 should throw an error. */
    int DIV();

    /* CMP -- Pops the top two values from the stack.  If the first is greater than the second, push 1.
     * If they are equal, push 0, if the second is greater than the first, push -1. */
    int CMP();
