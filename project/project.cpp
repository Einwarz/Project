#include <iostream>
#include <filesystem>
#include <windows.h>
#include <comutil.h>
#include <wbemcli.h>
#include <fileapi.h>

namespace fs = std::filesystem;

int main()
{
    fs::path diskpath;
    std::cout << "Input the name of Disk: ";
    std::cin >> diskpath;
    std::string Disk_path;
    Disk_path = diskpath.string();
    try {
        fs::space_info space = fs::space(diskpath);
        std::cout << "Total storage in " << diskpath << " is: " << space.capacity << " bytes" << std::endl;
        std::cout << "Remaining space on " << diskpath << " is: " << space.available << " bytes" << std::endl;

    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    //std::cout << Disk_path;
    //LPCWSTR name_drive = "L" + Disk_path;
    //Disk_path = "\"" + Disk_path + "\"";
    //Disk_path = "L" + Disk_path;
    //std::cout << Disk_path << std::endl;

    std::wstring tmp = std::wstring(Disk_path.begin(), Disk_path.end());
    LPCWSTR name_drive = tmp.c_str();
    std::wcout << name_drive << std::endl;

    UINT test;
    test = GetDriveType(name_drive);
    //std::wcout << test << std::endl;
    switch (test)
    {

    case 0: printf("Drive %S is type %d - Cannot be determined.\n", name_drive, test);

        break;

    case 1: printf("Drive %S is type %d - Invalid root path/Not available.\n", name_drive, test);

        break;

    case 2: printf("Drive %S is type %d - Removable.\n", name_drive, test);

        break;

    case 3: printf("Drive %S is type %d - Fixed.\n", name_drive, test);

        break;

    case 4: printf("Drive %S is type %d - Network.\n", name_drive, test);

        break;

    case 5: printf("Drive %S is type %d - CD-ROM.\n", name_drive, test);

        break;

    case 6: printf("Drive %S is type %d - RAMDISK.\n", name_drive, test);

        break;

    default: "Unknown value!\n";

    }
    return 0;
}