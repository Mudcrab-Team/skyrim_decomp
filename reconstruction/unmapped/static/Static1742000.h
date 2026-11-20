// Source exposure: binary-analysis; no external implementation source reused.
// Static1742000, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742000;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742000*);
    virtual void release(Static1742000*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742000*);
struct Static1742000 {
    void* value;
    Static1742000();
    ~Static1742000() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
