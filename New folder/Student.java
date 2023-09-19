public class Student {
    private String name;
    private String id;
    private String group;
    private String email;

    public  Student() {
        this.name = "Student";
        this.email = "uet@vnu.edu.vn";
        this.id = "000";
        this.group = "K62CB";
    }
    public Student(String name, String id, String email) {
        this.name = name;
        this.id = id;
        this.email=email;
        this.group = "K62CB";
    }
    public Student(Student s) {
        this.name = s.name;
        this.email = s.email;
        this.group = s.group;
        this.id = s.id;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void  setId(String id) {
        this.id = id;
    }
    public void setGroup(String group) {
        this.group = group;
    }
    public void setEmail(String email) {
        this.email = email;
    }
    public String getName() {
        return this.name;
    }
    public String getId() {
        return this.id;
    }
    public String getGroup() {
        return this.group;
    }
    public String getEmail() {
        return this.email;
    }
    public String getInfo() {
        return this.name + " - " + this.id + " - " + this.group + " - " + this.email;
    }
}
