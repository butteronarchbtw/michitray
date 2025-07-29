GCOVR_FLAGS=--merge-mode-function=merge-use-line-0
EXCLUDES=--exclude=../subprojects/ --exclude=../src/main.cpp
OUT=output
BUILD=../build

all: txt html cobertura
	@:

.PHONY: txt html cobertura clean

txt: 
	@gcovr -r .. $(BUILD) $(EXCLUDES) $(GCOVR_FLAGS) --txt

html: $(OUT)/coverage.html

cobertura: $(OUT)/cobertura.xml

$(OUT)/coverage.html:
	@- mkdir -p $(OUT)
	@gcovr -r .. $(BUILD) $(EXCLUDES) $(GCOVR_FLAGS) --html-details --html -o $@

$(OUT)/cobertura.xml:
	@- mkdir -p $(OUT)
	@gcovr -r .. $(BUILD) $(EXCLUDES) $(GCOVR_FLAGS) --cobertura-pretty --cobertura -o $@

clean:
	@- rm -rf $(OUT)
