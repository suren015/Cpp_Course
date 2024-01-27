#include <bits/stdc++.h>
using namespace std;

void decodeSequence(const string &binarySequence)
{
    unordered_map<string, char> nucleobase_mapping = {
        {"001", 'C'},
        {"010", 'G'},
        {"011", 'A'},
        {"101", 'T'},
        {"110", 'U'}};

    if (binarySequence.length() % 3 != 0)
    {
        cout << "Invalid input length" << endl;
        return;
    }

    string first_three_bits = binarySequence.substr(0, 3);
    string remaining_sequence = binarySequence.substr(3);

    string decoded_sequence;

    for (size_t i = 0; i < remaining_sequence.length(); i += 3)
    {
        string codon = remaining_sequence.substr(i, 3);
        decoded_sequence += nucleobase_mapping[codon];
    }

    if (first_three_bits == "000")
    {
        size_t pos = 0;
        while ((pos = decoded_sequence.find('U', pos)) != string::npos)
        {
            decoded_sequence.replace(pos, 1, "T");
            pos += 1;
        }
    }

    cout << decoded_sequence << endl;
}

int main()
{
    string input = "010001011101010110110100";
    decodeSequence(input);

    return 0;
}
