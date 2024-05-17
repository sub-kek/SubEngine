PROJECT_NAME = SubEngine

all:
	${MAKE} clean
	${MAKE} build
	${MAKE} run

clean:
	rm -r build

build:
	cmake -S . -B ./build -G Ninja
	cmake --build ./build
	chmod -R 777 ./build

run:
	build/${PROJECT_NAME}