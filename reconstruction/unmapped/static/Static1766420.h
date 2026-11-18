// Source exposure: binary-analysis; no external implementation source reused.
// Static1766420, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766420;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766420*);
    virtual void release(Static1766420*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766420*);
struct Static1766420 {
    void* value;
    Static1766420();
    ~Static1766420() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
