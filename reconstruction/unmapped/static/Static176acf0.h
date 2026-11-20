// Source exposure: binary-analysis; no external implementation source reused.
// Static176acf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176acf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176acf0*);
    virtual void release(Static176acf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176acf0*);
struct Static176acf0 {
    void* value;
    Static176acf0();
    ~Static176acf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
