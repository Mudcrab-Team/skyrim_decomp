// Source exposure: binary-analysis; no external implementation source reused.
// Static1764710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764710*);
    virtual void release(Static1764710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764710*);
struct Static1764710 {
    void* value;
    Static1764710();
    ~Static1764710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
