// Source exposure: binary-analysis; no external implementation source reused.
// Static1764670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764670*);
    virtual void release(Static1764670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764670*);
struct Static1764670 {
    void* value;
    Static1764670();
    ~Static1764670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
