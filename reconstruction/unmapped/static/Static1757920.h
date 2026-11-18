// Source exposure: binary-analysis; no external implementation source reused.
// Static1757920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757920*);
    virtual void release(Static1757920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757920*);
struct Static1757920 {
    void* value;
    Static1757920();
    ~Static1757920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
