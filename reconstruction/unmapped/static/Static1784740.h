// Source exposure: binary-analysis; no external implementation source reused.
// Static1784740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784740*);
    virtual void release(Static1784740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784740*);
struct Static1784740 {
    void* value;
    Static1784740();
    ~Static1784740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
