EXCLUDES=--exclude=../subprojects/ --exclude=../build/src/parser/ --exclude=../src/parser --exclude=../src/parser --exclude=../src/main.c
OUT=output
BUILD=../build

all: txt html cobertura
	@:

.PHONY: txt html cobertura clean

txt: 
	@gcovr -r .. $(BUILD) $(EXCLUDES) --txt

html: $(OUT)/coverage.html

cobertura: $(OUT)/cobertura.xml

$(OUT)/coverage.html:
	@- mkdir -p $(OUT)
	@gcovr -r .. $(BUILD) $(EXCLUDES) --html-details --html -o $@

$(OUT)/cobertura.xml:
	@- mkdir -p $(OUT)
	@gcovr -r .. $(BUILD) $(EXCLUDES) --cobertura-pretty --cobertura -o $@

clean:
	@- rm -rf $(OUT)
