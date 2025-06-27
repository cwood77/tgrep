all: debug

debug: bin/out/debug/tgrep.exe

.PHONY: all debug

bin/out/debug/tgrep.exe : bin/int/1/tgrep.exe
	@cp $< $@

bin/int/0/tgrep-commandLine.o : src/tgrep/commandLine.cpp src/tgrep/commandLine.hpp
	$(info $< --> $@)
	@x86_64-w64-mingw32-g++ -ggdb -D cdwDebugMode -c -Wall -D cdwTest -Wno-invalid-offsetof -D cdwAppDataName=\"tgrep\" src/tgrep/commandLine.cpp -o $@

bin/int/0/tgrep-error.o : src/tgrep/error.cpp src/tgrep/error.hpp
	$(info $< --> $@)
	@x86_64-w64-mingw32-g++ -ggdb -D cdwDebugMode -c -Wall -D cdwTest -Wno-invalid-offsetof -D cdwAppDataName=\"tgrep\" src/tgrep/error.cpp -o $@

bin/int/0/tgrep-finder.o : src/tgrep/finder.cpp src/tgrep/error.hpp src/tgrep/finder.hpp src/tgrep/string.hpp
	$(info $< --> $@)
	@x86_64-w64-mingw32-g++ -ggdb -D cdwDebugMode -c -Wall -D cdwTest -Wno-invalid-offsetof -D cdwAppDataName=\"tgrep\" src/tgrep/finder.cpp -o $@

bin/int/0/tgrep-main.o : src/tgrep/main.cpp src/tgrep/commandLine.hpp src/tgrep/error.hpp src/tgrep/finder.hpp src/tgrep/reader.hpp
	$(info $< --> $@)
	@x86_64-w64-mingw32-g++ -ggdb -D cdwDebugMode -c -Wall -D cdwTest -Wno-invalid-offsetof -D cdwAppDataName=\"tgrep\" src/tgrep/main.cpp -o $@

bin/int/0/tgrep-reader.o : src/tgrep/reader.cpp src/tgrep/error.hpp src/tgrep/reader.hpp src/tgrep/string.hpp
	$(info $< --> $@)
	@x86_64-w64-mingw32-g++ -ggdb -D cdwDebugMode -c -Wall -D cdwTest -Wno-invalid-offsetof -D cdwAppDataName=\"tgrep\" src/tgrep/reader.cpp -o $@

bin/int/0/tgrep-string.o : src/tgrep/string.cpp src/tgrep/string.hpp
	$(info $< --> $@)
	@x86_64-w64-mingw32-g++ -ggdb -D cdwDebugMode -c -Wall -D cdwTest -Wno-invalid-offsetof -D cdwAppDataName=\"tgrep\" src/tgrep/string.cpp -o $@

bin/int/1/tgrep.exe : bin/int/0/tgrep-commandLine.o bin/int/0/tgrep-error.o bin/int/0/tgrep-finder.o bin/int/0/tgrep-main.o bin/int/0/tgrep-reader.o bin/int/0/tgrep-string.o
	$(info   * --> $@)
	@x86_64-w64-mingw32-g++ -o $@  bin/int/0/tgrep-commandLine.o bin/int/0/tgrep-error.o bin/int/0/tgrep-finder.o bin/int/0/tgrep-main.o bin/int/0/tgrep-reader.o bin/int/0/tgrep-string.o -ggdb -static-libgcc -static-libstdc++ -static

