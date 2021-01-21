#include <iostream>
#include <string>
#include <filesystem>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define R_OK 4

using namespace std;
namespace fs = filesystem;

int TOTAL_LINES = 0;
int TOTAL_FILES = 0;

void search(string path, string ext, string space);
bool isbinary(string path);

void cpp_version()
{
    cout << __cplusplus << endl;
}

int main(int argc, char *argv[])
{
    string path = ".";
    string ext = "";

    if (argc > 1)
    {
        path = string(argv[1]);
    }

    if (argc > 2)
    {
        ext = string(argv[2]);
    }

    cout << "we are looking at: " << path << endl;

    search(path, ext, "");

    cout << "TOTAL FILES: " << TOTAL_FILES << endl;
    cout << "TOTAL LINES: " << TOTAL_LINES << endl;

    return 0;
}

string exec(const char *cmd)
{
    char buffer[128];
    std::string result = "";
    FILE *pipe = popen(cmd, "r");
    if (!pipe)
        throw std::runtime_error("popen() failed!");
    try
    {
        while (fgets(buffer, sizeof(buffer), pipe) != NULL)
        {
            result += buffer;
        }
    }
    catch (int e)
    {
        pclose(pipe);
        cout << "err: " << e << endl;
        throw;
    }
    pclose(pipe);
    return result;
}

int count(string path)
{
    string cmd = "/bin/env wc -l '" + path + "'";
    string res = exec(cmd.c_str());
    string::size_type sz;
    return stoi(res, &sz);
}

bool isbinary(string path)
{
    string cmdStr = "/bin/env file '" + path + "'";
    string res = exec(cmdStr.c_str());
    res = res.substr(res.find(":") + 1, res.length());
    // cout << "path: " << path << " res: " << res << endl;
    if (res.find("UTF-8") != string::npos || res.find("text") != string::npos || res.find("ASCII") != string::npos)
    {
        return false;
    }

    return true;
}

void search(string path, string ext, string space)
{
    /* Check read access. */
    int rval = access(path.c_str(), R_OK);

    if (rval == 0)
        for (const auto &entry : fs::directory_iterator(path))
        {
            bool isdir = entry.is_directory();
            if (!isdir)
            {
                if (ext != "")
                {
                    string p = entry.path().string();
                    string fext = p.substr(p.find_last_of(".") + 1, p.length());
                    // cout << "P: " << p << " fext::" << fext << " ext: " << ext << endl;
                    if (fext != ext)
                    {
                        continue;
                    }
                }

                if (!isbinary(entry.path()))
                {
                    cout << entry.path() << endl;
                    int lines_count = count(entry.path());
                    TOTAL_LINES += lines_count;
                    TOTAL_FILES++;
                    cout << "lines: " << lines_count << endl;
                }
            }

            if (isdir)
            {
                search(entry.path(), ext, space + "\t");
            }
        }
}
