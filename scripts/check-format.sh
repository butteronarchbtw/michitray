#!/bin/bash

check_c_style() {
	echo "checking c style ..."
	if [[ -z "$(command -v "$1")" ]]; then
		echo "error: $1 not found"
		echo "please install clang-format for formatting"
		exit 1
	fi

	find src include -type f -name "*.[ch]" -print0 | xargs -0 -P"$(nproc)" -n2 "$1" -n -Werror &>> clang-format.log

	rc=0
	if grep -q "error" clang-format.log; then
		echo "ERROR"
		echo ""
		cat clang-format.log
		rc=1
	else
		echo "OK"
	fi

	rm clang-format.log

	return $rc
}

check_meson_style() {
	echo "checking meson style ..."
	if [[ -z "$(command -v "$1")" ]]; then
		echo "error: $1 not found"
		echo "please install meson for formatting"
		exit 1
	fi

	find . -type f -name "meson.build" ! -path "./subprojects/*" -exec meson fmt -q {} +
	rc=$?

	if [[ "$rc" -eq 0 ]]; then
		echo "OK"
	else
		echo "ERROR"
	fi

	return $rc
}

CLANG_FORMAT_BIN="${CLANG_FORMAT_BIN:-"clang-format"}"

check_c_style "$CLANG_FORMAT_BIN" || exit 1
check_meson_style meson || exit 1
