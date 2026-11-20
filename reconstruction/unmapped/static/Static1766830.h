// Source exposure: binary-analysis; no external implementation source reused.
// Static1766830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766830*);
    virtual void release(Static1766830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766830*);
struct Static1766830 {
    void* value;
    Static1766830();
    ~Static1766830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
