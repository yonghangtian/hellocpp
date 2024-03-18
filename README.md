# hello C++

In CppPrimerPlus folder, my solutions to <C++ primer plus 6th edition> 's programming exercises (including chapter 1 to chaper 18).

Above work has been done between 2022 Oct and 2023 Aug.

I'm doing <cpp primer 5th edition> 's programming exercises from 2023 Sep 17.

## Dev Stack:
 windows 11 + wsl2 + unbuntu22.04(until 2024 March 12) + centos7.9(starting from 2024 March 14)

MySQL connector's guide, please check "mysqlconnector_readme.md", note: mysql connector 8.3.0 CANNOT run on centos7.9's glibc(2.17), therefore, I have to use 1.1.12

Cppcheck 2.13 is installed from source code :
>  $ tar -zxvf cppcheck-2.13.0.tar.gz && cd cppcheck-2.13.0
>
>  $ yum isntall pcre2.x86_64 pcre2-devel.x86_64
>
>  $ yum install pcre2.x86_64 pcre2-devel.x86_64
>
>  $ make MATCHCOMPILER=yes FILESDIR=/usr/share/cppcheck HAVE_RULES=yes CXXFLAGS="-O2 -DNDEBUG -Wall -Wno-sign-compare -Wno-unused-function"
>
>  $ make install MATCHCOMPILER=yes FILESDIR=/usr/share/cppcheck
>
>  $ cppcheck --version

## Note:
Below dirs are downloaded from their official website, therefore, I add them in .gitignore.
>    [CppPrimer5th/examples](http://informit.com/title/0321714113 "cpp primer 5th source code")
>
>    CppPrimerPlus/examples 
