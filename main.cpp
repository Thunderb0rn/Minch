#include<iostream>
#include<string>
#include<vector>

#define M_TO_INCH   2.54

double inch2m(double inch) {
    return inch*M_TO_INCH;
}

double m2inch(double metric) {
    return metric/M_TO_INCH;
}

void help() {
    std::cout  << "\e[1mminch\e[0m [\e[1margument\e[0m] <\e[1mvalue\e[0m>" << std::endl;
    std::cout << "\e[1m--help [-h]\e[0m\t\tPrintin this message\n";
    std::cout << "\e[1m--inch2metr [-i2m]\e[0m\tInches into centimetres.\n";
    std::cout << "\e[1m--metr2inch [-m2i]\e[0m\tСentimetres into шnches.\n";

}

void remove(std::vector<std::string>& vec, size_t pos) {
    std::vector<std::string>::iterator itr = vec.begin();
    std::advance(itr, pos);
    vec.erase(itr);

}

int main(int argc, char** argv) {
    std::vector<std::string> argument;

    for (int i = 1; i < argc; i++) {
        argument.push_back( std::string( argv[i] ) );
    }

    if (argument.size() == 0) {
        help();
        return -1;
    }

    for (int i =0; i < (int)argument.size(); i++) {
        if (argument.at(i) == "--help" || argument.at(i) == "-h") { 
            help();
            remove(argument, i);
        } else if (argument.at(i) == "--inch2metr" || argument.at(i) == "-i2m") {
            double inch = std::stod(argument.at(i+1));
            std::cout << inch2m(inch) << std::endl;
            return 0;

        } else if (argument.at(i) == "--metr2inch" || argument.at(i) == "-m2i") {
            double metr = std::stod(argument.at(i+1));
            std::cout << m2inch(metr) << std::endl;
            return 0;
        } else {
            help();
            remove(argument, i);
            return -1;
        }
    }

    return 0;
    
}
