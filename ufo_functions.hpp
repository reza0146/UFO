#include <vector>
#include <string>


void display_misses(int misses);
void display_status(std::string answer, std::string guess, std::vector<int> red_pos);
void Greet();
std::string BuildBlankAnswer(std::string codeword);
void EndGame(std::string codeword, std::string answer);
void SetColorRed();
void ResetColor();
std::string get_substring(std::string input, std::vector<int> indices);