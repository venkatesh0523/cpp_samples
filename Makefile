# Simple sample runner for C++ programs.
CXX := g++
# CXXFLAGS := -std=c++23 -Wall -Wextra -O2
CXXFLAGS := -std=c++23 -Wall -Wextra -O2 -fmodules-ts
BIN_DIR := bin
SRC_DIR := src

SAMPLES := $(basename $(notdir $(wildcard $(SRC_DIR)/*.cpp)))
BINS := $(patsubst %,$(BIN_DIR)/%,$(SAMPLES))

.PHONY: all list run clean new
all: $(BINS)

#$(BIN_DIR)/%: $(SRC_DIR)/%.cpp | $(BIN_DIR)
#	$(CXX) $(CXXFLAGS) -o $@ $<
$(BIN_DIR)/%: $(SRC_DIR)/%.cpp $(SRC_DIR)/math.cppm | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -x c++ -c $(SRC_DIR)/math.cppm -o $(BIN_DIR)/math.o
	$(CXX) $(CXXFLAGS) -o $@ $< $(BIN_DIR)/math.o

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

list:
	@printf "Available samples:\n"
	@for f in $(SAMPLES); do printf "  %s\n" $$f; done

run: $(BIN_DIR)
ifndef NAME
	$(error NAME is not set. Example: make run NAME=hello)
endif
	$(MAKE) $(BIN_DIR)/$(NAME)
	./$(BIN_DIR)/$(NAME)

new:
ifndef NAME
	$(error NAME is not set. Example: make new NAME=hello)
endif
	@mkdir -p $(SRC_DIR)
	@if [ -e $(SRC_DIR)/$(NAME).cpp ]; then \
		echo "Sample '$(NAME)' already exists."; exit 1; \
	fi
	@cat > $(SRC_DIR)/$(NAME).cpp <<'EOF'
	#include <iostream>
	
	int main(int argc, char* argv[]) {
	    std::cout << "Sample $(NAME) running\n";
	    std::cout << "Arguments:";
	    for (int i = 1; i < argc; ++i) {
	        std::cout << " " << argv[i];
	    }
	    std::cout << '\n';
	    return 0;
	}
	EOF
	@echo "Created $(SRC_DIR)/$(NAME).cpp"

clean:
	rm -rf $(BIN_DIR)
