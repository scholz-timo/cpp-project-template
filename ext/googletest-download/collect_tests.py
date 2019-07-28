import os

def collect_files(path, possible_extensions):
    files = []
    directories = [path]
    
    while (len(directories) > 0):
        directory = directories.pop()
        for r, d, f in os.walk(directory):
            for file in f:
                if file.lower().endswith(possible_extensions):
                    files.append(os.path.join(r, file))
            for directory in d:
                directories.push(os.path.join(r, directory))
    
    return files


target_filename1 = "include_tests.hh"
f1 = open(target_filename1, "w")

target_filename2 = "CMakeLists.txt"
f2 = open(target_filename2, "w")


f1.write("#include \"gtest/gtest.h\"\n")

current_dir = os.getcwd()
for file in collect_files(current_dir, ('.hh', '.hxx', '.hpp')):
    relative_file = os.path.relpath(file, current_dir)
    if relative_file != target_filename1 and relative_file != target_filename2:
        f1.write("#include \"" + relative_file + "\"\n")
        f2.write("add_sources(\"" + relative_file + "\")\n")

f1.close()
f2.close()