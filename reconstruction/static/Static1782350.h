// Source exposure: binary-analysis; no external implementation source reused.
// Static1782350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782350*);
    virtual void release(Static1782350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782350*);
struct Static1782350 {
    void* value;
    Static1782350();
    ~Static1782350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
