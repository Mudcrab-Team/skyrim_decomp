// Source exposure: binary-analysis; no external implementation source reused.
// Static1754770, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754770;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754770*);
    virtual void release(Static1754770*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754770*);
struct Static1754770 {
    void* value;
    Static1754770();
    ~Static1754770() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
