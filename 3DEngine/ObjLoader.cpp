#include "ObjLoader.h"

#include <sstream>
#include <fstream>

std::vector<std::string> split(std::string input, char c = ' ') {
    std::stringstream test(input);
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(test, segment, c))
    {
        seglist.push_back(segment);
    }
    return seglist;
}

Object* loadObject(std::string location){
    Object* object = new Object;
    std::ifstream file(location);
    std::string str;
    
    while (std::getline(file, str))
    {
        // load Vertices
        if (str[0] == 'v' && str[1] == ' ') 
        {
            std::vector<std::string> line = split(str);
            object->vertices.push_back(Vector3D(stof(line[1]) / 2.0f, stof(line[2]) / 2.0f, -stof(line[3]) / 2.0f));

        }
        // load Indices
        else if (str[0] == 'f') {
            std::vector<std::string> line = split(str);
            //std::cout << split(line[1], '/')[0] << '\n';
            object->indices.push_back(stoi(split(line[1], '/')[0]) - 1);
            object->indices.push_back(stoi(split(line[2], '/')[0]) - 1);
            object->indices.push_back(stoi(split(line[3], '/')[0]) - 1);


            if (line.size() == 5) {
                object->indices.push_back(stoi(split(line[1], '/')[0]) - 1);
                object->indices.push_back(stoi(split(line[3], '/')[0]) - 1);
                object->indices.push_back(stoi(split(line[4], '/')[0]) - 1);
            }
        }
    }
    return object;
}

