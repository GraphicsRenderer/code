build:
	@mkdir -p build
	@cd build && cmake ..
	@cd build && cmake --build . --config Release

clean:
	rm -rf build

.PHONY: build clean
