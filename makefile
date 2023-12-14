.PHONY: build install pack test help clean

define PRINT_HELP_PYSCRIPT
import re, sys
for line in sys.stdin:
	match = re.match(r'^([a-zA-Z_-]+):.*?## (.*)$$', line)
	if match:
		target, help = match.groups()
		print("%-20s %s" % (target, help))
endef
export PRINT_HELP_PYSCRIPT

# Release or Debug
build_type=Release
build_dir=build
project_dir := $(shell pwd)

help:
	@python3 -c "$$PRINT_HELP_PYSCRIPT" < $(MAKEFILE_LIST)

pack: build ## 打包代码
	@cd $(project_dir)/build && cpack && cd -

test:  ## 编译代码和单元测试
	@cmake -B $(project_dir)/$(build_dir) \
		  -DCMAKE_BUILD_TYPE=$(build_type) \
		  -DENABLE_TEST=ON \
		  -DCMAKE_TOOLCHAIN_FILE=$(project_dir)/cmake/ToolChain.cmake
	@cmake --build $(project_dir)/$(build_dir) --parallel

build: ## 编译代码
	@cmake -B $(project_dir)/$(build_dir) \
		  -DCMAKE_BUILD_TYPE=$(build_type) \
		  -DCMAKE_TOOLCHAIN_FILE=$(project_dir)/cmake/ToolChain.cmake
	@cmake --build $(project_dir)/$(build_dir) --parallel

check:  ## 静态检测代码
	@cmake -B $(project_dir)/$(build_dir) \
		  -DCMAKE_BUILD_TYPE=$(build_type) \
		  -DENABLE_STATIC_ANALYSIS=ON \
		  -DCMAKE_TOOLCHAIN_FILE=$(project_dir)/cmake/ToolChain.cmake
	@cmake --build $(project_dir)/$(build_dir) --parallel

clean: ## 删除编译缓存
	@rm -rf $(build_dir) $(output_dir)
