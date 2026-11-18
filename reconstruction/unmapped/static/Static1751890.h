// Source exposure: binary-analysis; no external implementation source reused.
// Static1751890, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751890;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751890*);
    virtual void release(Static1751890*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751890*);
struct Static1751890 {
    void* value;
    Static1751890();
    ~Static1751890() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
