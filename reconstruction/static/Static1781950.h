// Source exposure: binary-analysis; no external implementation source reused.
// Static1781950, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781950;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781950*);
    virtual void release(Static1781950*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781950*);
struct Static1781950 {
    void* value;
    Static1781950();
    ~Static1781950() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
