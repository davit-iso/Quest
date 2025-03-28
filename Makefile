# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -Wall -Wextra -std=c++17 -Iheaders

# Папки
SRC_DIR = src
HEADER_DIR = headers
BUILD_DIR = build

# Все файлы .cpp в src/
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Создание объектных файлов в build/
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Итоговый исполняемый файл
TARGET = main

# Правило по умолчанию (сборка всего проекта)
all: $(TARGET)

# Компоновка исполняемого файла
$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $@

# Компиляция .cpp файлов в .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Создание папки build, если её нет
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Очистка собранных файлов
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Фиктивная цель, чтобы make не путал её с файлами
.PHONY: all clean
