// Source exposure: binary-analysis; no external implementation source reused.
// Static1752060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752060*);
    virtual void release(Static1752060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752060*);
struct Static1752060 {
    void* value;
    Static1752060();
    ~Static1752060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
