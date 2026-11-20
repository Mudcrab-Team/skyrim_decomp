// Source exposure: binary-analysis; no external implementation source reused.
// Static1757f60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757f60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757f60*);
    virtual void release(Static1757f60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757f60*);
struct Static1757f60 {
    void* value;
    Static1757f60();
    ~Static1757f60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
