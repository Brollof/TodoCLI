project('todocli', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

src = ['main.cpp', 'CSVFile.cpp', 'Todo.cpp']

if get_option('buildtype') == 'custom'
  add_project_arguments('-Ofast', '-g3',  language : 'cpp')
endif

executable('todocli',
           sources: src,
           install : true)