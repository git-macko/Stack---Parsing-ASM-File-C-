#include "cpu.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

CPU::CPU() {}

ifstream myFile; //parsing ASM file.

void CPU::LoadProgram(string filename) {
    stack.clear(); //ensures that stack is empty.

    myFile.open(filename); //opens file.
    if(!myFile) //throws an error if file not found.
        throw runtime_error("FILE NOT FOUND! CALL 911.");
    cout << "--------------------------------------------------------" << endl;
    cout << "File " << filename << " Contents: \n"; //labeling the loaded file and its contents

}



int CPU::Run() {

    while(myFile) {
        string line;
        int value;
        getline(myFile, line, ' '); //gets the string in the line and stops when detects space

        myFile >> value; //inputs integers from a file to int num
        if(!myFile) { //stops reading when there's no more content in a line.
            break;
        }
        stack.insert(stack.begin(), value); //adds the integers in the stack.

    }
    myFile.close();

    cout << "Stack Size: " << stack.size() << endl;

    while(stack.size() != 1) { //removes values in the stack and returns the last.
        stack.pop_back(); //removes the element in the back.
    }

    if(stack.size() >= 2) //throwing an error if there's still 2 or more values in stack.
        throw runtime_error("ERROR: STACK HAS TWO VALUES. CALL 911.");


    cout << "The Only Value Left: " << stack.front() << endl;
    cout << "Stack Size after Run() executes : " << stack.size() << endl;

    return 0;
}

int CPU::Next() {
    string lineFunction;
    string command;
    //getting line from the file.
    getline(myFile, lineFunction);
    //LEARN AND IMPLEMENT SUBSTR THAT READS AND SEPARATES STRING AND INTEGER.

    //Separating the Command from the Value
    if(lineFunction.length() == 3){
        command = lineFunction.substr(0,3); //command
    }
    else if(lineFunction.length() == 4) {
        command = lineFunction.substr(0,4);
    }
    else if(lineFunction.length() == 5) {
        command = lineFunction.substr(0,3); //command
        value = stoi(lineFunction.substr(4,5)); //value
    }

    //Command comes to play
    if(command == "PSH") { //if line contains PSH, then call function PSH()
        return PSH();
    }
    else if(command == "ADD") { //if line contains ADD, then call function ADD()
        return ADD();
    }
    else if(command == "SUB") { //if line contains SUB, then call function SUB()
        return SUB();
    }
    else if(command == "MULT") { //if line contains MULT, then call function MULT()
        return MULT();
    }
    else if(command == "DIV") { //if line contains DIV, then call function DIV()
        return DIV();
    }
    else if(command == "CMP") { //if line contains CMP, then call function CMP()
        return CMP();
    }

    myFile.close(); //Closes program after command
    return -1;
}

//output overload that prints the current stack
ostream& operator << (ostream& output, CPU& a)
{
    for(int i=0; i < a.stack.size(); i++) { //prints the current stack
        output << a.stack.at(i) << ", ";
    }
    return output; //outputs the value and order received that met the condition
}

int CPU::PSH() {
    stack.insert(stack.begin(), value); //pushes values onto the stack
    return 0; //returns Next()==0
}

int CPU::ADD() {
    int first = stack.at(0); //getting the top and second value from stack.
    int second = stack.at(1);
    while(stack.size() != 4) { //pops the top 2 value.
        stack.erase(stack.begin());
    }
    value = first + second; //sum operation
    stack.insert(stack.begin(), value); //pushes the sum onto the stack.
    return 0; //returns Next()==0
}

int CPU::SUB() {
    int first = stack.at(0);//getting the top and second value from stack.
    int second = stack.at(1);
    while(stack.size() != 3) { //pops the top 2 value.
        stack.erase(stack.begin());
    }
    value = second - first; //subtraction operation
    stack.insert(stack.begin(), value); //pushes the difference onto the stack.
    return 0; //returns Next()==0
}

int CPU::MULT() {
    int first = stack.at(0);//getting the top and second value from stack.
    int second = stack.at(1);
    while(stack.size() != 2) { //pops the top 2 value.
        stack.erase(stack.begin());
    }
    value = first * second; //multiplication operation
    stack.insert(stack.begin(), value); //pushes the product onto the stack.
    return 0; //returns Next()==0
}

int CPU::DIV() {
    int first = stack.at(0);//getting the top and second value from stack.
    int second = stack.at(1);
    while(stack.size() != 1) { //pops the top 2 value.
        stack.erase(stack.begin());
    }
    if(first == 0) //throws error if divided by 0
        throw runtime_error("FIRST VALUE IS 0! CALL 911");
    try {
        value = second / first; //divide operation
        stack.insert(stack.begin(), value); //pushes the dividend onto the stack.
    }
    catch(...) {
        cout << "FIRST VALUE IS 0! CALL 911" << endl;
    }


    return 0; //returns Next()==0
}

int CPU::CMP() {
    int first = stack.at(0);//getting the top and second value from stack.
    int second = stack.at(1);
    while(stack.size() != 0) { //pops the top 2 values.
        stack.erase(stack.begin());
    }
    //compare!
    if(first > second) {
        stack.insert(stack.begin(), value); //pushes 1 if top is greater than second
    }
    else if(first == second) {
        stack.insert(stack.begin(), value); //pushes 0 if top is equal to second
    }
    else if(second > first) {
        stack.insert(stack.begin(), value); //pushes -1 if second is greater than top
    }
    return 0; //returns Next()==0
}
