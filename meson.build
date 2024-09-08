project('todocli', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

inc = [include_directories('include'), include_directories('libs')]
src = ['src/main.cpp', 'src/CSVFile.cpp', 'src/Todo.cpp', 'src/Printer.cpp']

executable('todocli',
           include_directories : inc,
           sources: src,
           install : true)