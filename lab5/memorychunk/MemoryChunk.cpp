//
// Created by agnieszka on 28.03.17.
//

#include "MemoryChunk.h"
namespace memorychunk
{

    MemoryChunk::MemoryChunk(size_t sz)
    {
        ptr=new int8_t[sz];
    }
    int8_t *MemoryChunk::MemoryAt(size_t offset) const
    {

    }
    size_t MemoryChunk::ChunkSize() const
    {

    }

    MemoryChunk::MemoryChunk(const MemoryChunk &m) {

    }

    MemoryChunk::MemoryChunk(MemoryChunk &&m) {

    }

    MemoryChunk &MemoryChunk::operator=(const MemoryChunk &m) {

    }

    MemoryChunk &MemoryChunk::operator=(MemoryChunk &&m) {

    }

    MemoryChunk::~MemoryChunk() {
        delete []ptr;
    }
}