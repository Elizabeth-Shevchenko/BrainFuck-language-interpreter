﻿#ifndef CURRENTCELL_H
#define CURRENTCELL_H

#include <vector>
#include <string>

namespace DataPointerArray
{
    class ArrayCellsException : public std::exception
    {
    private:
        std::string m_message;

    public:
        explicit ArrayCellsException(const std::string& message) : m_message(message) {}

        const char *what() const throw()
        {
            return m_message.c_str();
        }
    };

    /* Holds current state of the movable data pointer */
    class ArrayCells
    {
    private:
        std::vector<int> m_cells;
        int m_currentCell; // current cell number

    public:
        static const int BYTE_CELLS_MAX_COUNT = 30000;

        ArrayCells() : m_cells(BYTE_CELLS_MAX_COUNT, 0), m_currentCell(0) {}

        ArrayCells(const ArrayCells&) = delete;
        ArrayCells& operator=(const ArrayCells&) = delete;

        // Main functionality
        void DecrDataPtrValue();
        void IncrDataPtrValue();
        void MoveDataPtrLeft();
        void MoveDataPtrRight();
        void InputDataPtrValue();
        void OutputDataPtrValue();
        void LoopBegin();
        void LoopEnd();

        void Reset();

        bool IsCurrentCellNull() const noexcept;
        int GetCurrentCell() const noexcept;
    };
}

#endif // CURRENTCELL_H
