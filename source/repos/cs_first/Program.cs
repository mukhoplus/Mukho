/*
 * 2021-07-02
 * Made By Mukho
 * at Chuncheon
 * C#
 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs_first
{
    public class User
    {
        // Field
        private string name;
        private int id;

        // Constructor
        public User()
        {
            name = string.Empty;
            id = -1;
        }
        public User(string name, int id)
        {
            this.name = name;
            this.id = id;
        }

        // Property
        public string Name { get; set; }
        public int Id
        {
            get { return id; }
            set { id = value; }
        }
        
        // Method
        public string GetUserData()
        {
            string data = string.Format("Name: {0}(Id: {1})", this.Name, this.Id);
            return data;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string name;
            name = Console.ReadLine();
            // int id = Convert.ToInt32(Console.ReadLine());
            int id = int.Parse(Console.ReadLine());
            Console.WriteLine("Hi {0}", name);

            User user = new User(name, id);
            var u = new User();
            string output = user.GetUserData();
            Console.WriteLine(output);

            u.Name = "Made By Google";
            u.Id = 22;
            output = u.GetUserData();
            Console.WriteLine(output);
        }
    }
}