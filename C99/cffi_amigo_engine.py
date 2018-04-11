import os

from cffi import FFI

ffibuilder = FFI()

PATH = os.path.dirname(__file__)

header = ""

with open(os.path.join(PATH, "Amigo_engine.h")) as f:
    global header
    header = f.read()
    ffibuilder.cdef(header + '''extern "Python"{
        void Amigo_InfoEvent(Amigo_Event_ event, BoolType pre);
        void Amigo_AssignInputVariables();}''', override=True)


with open(os.path.join(PATH, 'Amigo_engine.c'), 'r') as f:
    ffibuilder.set_source("_amigo_engine",
                          header + f.read(),
                          libraries=[],
                          # sources=[os.path.join(PATH, "amigo-library.c")],
                          include_dirs=[PATH, "/usr/include/"]
                          )


system_path = "/usr/include/"


if __name__ == "__main__":
    ffibuilder.compile(verbose=True)
