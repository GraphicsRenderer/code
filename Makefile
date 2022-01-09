build:
	@mkdir -p build
	@cd build && cmake ..
	@cd build && cmake --build . --config Release

fmt:
	@python3 clang-format.py

clean:
	rm -rf build

.PHONY: build fmt clean
