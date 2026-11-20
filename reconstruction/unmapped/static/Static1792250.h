// Source exposure: binary-analysis; no external implementation source reused.
// Static1792250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1792250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1792250*);
    virtual void release(Static1792250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1792250*);
struct Static1792250 {
    void* value;
    Static1792250();
    ~Static1792250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
