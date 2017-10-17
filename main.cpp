#include <iostream>
#include <vector>
#include <string>
#include <fstream>


class BrainfuckInterpreter {

    int memorySize_;
    int* memory_;
    std::string commands_;

public:
    explicit BrainfuckInterpreter(std::string const& codeStr) {
        commands_ = codeStr;
        memorySize_ = 30000;
        this->memory_ = new int[memorySize_];
        for (int i = 0; i  < memorySize_; ++i) {
            this->memory_[i] = 0;
        }
    }

    ~BrainfuckInterpreter() {
        delete[] this->memory_;
    }
    void printMemory() {
        std::cout << std::endl;
        for (int i = 0; i < 40; ++i) {
            std::cout << this->memory_[i] << " ";
        }
    }
    void begin() {
        int index = 0;
        std::vector<int> indexOfStratingLoop = std::vector<int>();
        int memoryIndex = 0;
        while (index < (int) this->commands_.length()) {
            switch ((char)commands_[index]) {
                case '>':{
                    ++memoryIndex;
                    break;
                }
                case '<':{
                    --memoryIndex;
                    break;
                }
                case '+':{
                    ++memory_[memoryIndex];
                    break;
                }
                case '-':{
                    --memory_[memoryIndex];
                    break;
                }
                case '[':{
                    if (!this->memory_[memoryIndex]) {
                        while(this->commands_[index] != ']') {
                            ++index;
                        }
                    } else {
                        indexOfStratingLoop.push_back(index);
                    }
                    break;
                }
                case ']':{
                    if (this->memory_[memoryIndex]) {
                        index = indexOfStratingLoop.back();
                    } else {
                        indexOfStratingLoop.pop_back();
                    }
                    break;
                }
                case '.':{
                    std::cout << (char) this->memory_[memoryIndex];
                    break;
                }
                case ',':{
                    char tmp;
                    std::cin >> tmp;
                    this->memory_[memoryIndex] = (int) tmp;
                    break;
                }
                default:break;
            }
            ++index;
        }
    }
};

std::string readFile(const std::string& fileName) {
    std::fstream file(fileName);
    std::string str;

    copy(
            std::istream_iterator<char>(file),
            std::istream_iterator<char>(),
            std::insert_iterator<std::string>(str,str.begin()));
    return str;
}

int main(int argc, char* argv[]) {
    std::string codeString;
    if (argc > 1) {
        codeString = readFile(argv[1]);
    } else {
        std::cout << "Enter brainfuck code" << std::endl;
        getline(std::cin, codeString);
    }
    BrainfuckInterpreter bfInterpreter(codeString);
    bfInterpreter.begin();
    std::cout << std::endl;
    return 0;
}

