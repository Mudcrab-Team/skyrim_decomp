// Source exposure: binary-analysis; no external implementation source reused.
// Static1764850, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764850;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764850*);
    virtual void release(Static1764850*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764850*);
struct Static1764850 {
    void* value;
    Static1764850();
    ~Static1764850() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
