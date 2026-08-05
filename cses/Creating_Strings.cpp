input/code.cpp: In function 'int32_t main()':
input/code.cpp:54:23: warning: comparison of integer expressions of different signedness: 'long long int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   54 |     for (int i = 0; i < s.size()-1; i++)
      |                     ~~^~~~~~~~~~~~
input/code.cpp:74:23: warning: comparison of integer expressions of different signedness: 'long long int' and 'std::vector<long long int>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   74 |     for (int i = 0; i < counts.size(); i++)
      |                     ~~^~~~~~~~~~~~~~~