#include "ArrayCells.h"
#include <string>
#include <iostream>

namespace DataPointerArray
{
    void ArrayCells::DecrDataPtrValue()
    {
        --m_cells[m_currentCell];
    }

    void ArrayCells::IncrDataPtrValue()
    {
        ++m_cells[m_currentCell];
    }

    void ArrayCells::MoveDataPtrLeft()
    {
        if (m_currentCell - 1 >= 0)
            --m_currentCell;
    }

    void ArrayCells::MoveDataPtrRight()
    {
        if (m_currentCell + 1 < BYTE_CELLS_MAX_COUNT)
            ++m_currentCell;
    }

    void ArrayCells::InputDataPtrValue()
    {
        std::cin >> m_cells[m_currentCell];
    }

    void ArrayCells::OutputDataPtrValue()
    {
        std::cout << char(m_cells[m_currentCell]);
    }

    void ArrayCells::Reset()
    {
        m_currentCell = 0;
        m_cells.clear();
        m_cells.assign(BYTE_CELLS_MAX_COUNT, 0);
    }

    bool ArrayCells::IsCurrentCellNull() const noexcept
    {
        return (0 == m_cells[m_currentCell]);
    }

    int ArrayCells::GetCurrentCell() const noexcept
    {
        return m_currentCell;
    }
}
