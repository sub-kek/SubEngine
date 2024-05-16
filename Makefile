PROJECT_NAME = SubEngine

all:
	${MAKE} clean
	${MAKE} build
	${MAKE} run

clean:
	rm -r build

build:
	cmake -S . -B build -G Ninja
	cmake --build build

run:
	build/${PROJECT_NAME}