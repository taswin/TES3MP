#ifndef INTERPRETER_RUNTIME_H_INCLUDED
#define INTERPRETER_RUNTIME_H_INCLUDED

#include <vector>

#include "types.hpp"

namespace Interpreter
{
    class Context;

    /// Runtime data and engine interface
    
    class Runtime
    {
            Context& mContext;
            const Type_Code *mCode;
            int mCodeSize;
            int mPC;
            std::vector<Type_Data> mStack;
            
        public:
        
            Runtime (Context& context);
        
            int getPC() const;
            ///< return program counter.
        
            int getIntegerLiteral (int index) const;
        
            float getFloatLiteral (int index) const;
                    
            void configure (const Type_Code *code, int codeSize);
            ///< \a context and \a code must exist as least until either configure, clear or
            /// the destructor is called. \a codeSize is given in 32-bit words.
            
            void clear();
            
            void setPC (int PC);
            ///< set program counter.
            
            void push (Type_Data data);
            ///< push data on stack
            
            void pop();
            ///< pop stack
            
            Type_Data& operator[] (int Index);
            ///< Access stack member, counted from the top.
            
            Context& getContext();
    };
}

#endif
