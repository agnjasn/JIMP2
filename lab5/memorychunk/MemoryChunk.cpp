//
// Created by agnieszka on 28.03.17.
//

#include "MemoryChunk.h"
namespace memorychunk
{

    MemoryChunk::MemoryChunk(size_t sz)
    {
        ptr=new int8_t[sz];
        this->sz=sz;
    }
    int8_t *MemoryChunk::MemoryAt(size_t offset) const
    {
        if(offset>=0 && offset<sz)
        return ptr+offset;
    }
    size_t MemoryChunk::ChunkSize() const
    {
        return sz;
    }

    MemoryChunk::MemoryChunk(const MemoryChunk &m) {
        ptr = new int8_t[m.ChunkSize()];
        std::copy(m.ptr,m.ptr+sz, ptr);
        sz=m.ChunkSize();
    }

    MemoryChunk::MemoryChunk(MemoryChunk &&m) {
        ptr=nullptr;
        std::swap(ptr, m.ptr);
        sz=0;
        std::swap(sz, m.sz);
    }

    MemoryChunk &MemoryChunk::operator=(const MemoryChunk &m) {
        if (this == &m) {
            return *this;
        }

        delete[] ptr;

        ptr = new int8_t[m.ChunkSize()];
        std::copy(m.ptr,m.ptr+sz, ptr);
        sz=m.ChunkSize();
    }

    MemoryChunk &MemoryChunk::operator=(MemoryChunk &&m) {
        //jeśli ktoś wpadł na pomsył x = move(x);
        if (this == &m) {
            return m;
        }

        delete[] ptr;

        ptr = nullptr;
        std::swap(ptr,m.ptr);
        sz=0;
        std::swap(sz, m.sz);
    }

    MemoryChunk::~MemoryChunk() {
        delete [] ptr;


    }
}