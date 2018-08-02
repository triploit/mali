typedef void (*constructor)();

extern "C" constructor start_ctors; 
extern "C" constructor end_ctors;
extern "C" void initialiseConstructors();

void initialiseConstructors() 
{
    for (constructor* i = &start_ctors;i != &end_ctors;++i)
        (*i)();
}