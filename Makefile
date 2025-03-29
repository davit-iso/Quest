# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -Wall -Wextra -std=c++17 -I./header

# Папки
SRC_DIR = src
HEADER_DIR = headers

# Все файлы .cpp в src/
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Итоговый исполняемый файл
TARGET = game

# Правило по умолчанию (сборка всего проекта)
all: $(TARGET)

# Компиляция всех .cpp в один исполняемый файл
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Очистка собранных файлов
clean:
	rm -f $(TARGET)

# Фиктивная цель, чтобы make не путал её с файлами
.PHONY: all clean
